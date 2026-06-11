#include<iostream>
using namespace std;

int n,q;
string s;
char t[200005],d[200005];
int poz[2];

int ok(int i,int p){

    for(int j=1;j<=q;j++)
        if(s[i]==t[j]){

            if(d[j]=='R') ++i;
            else --i;

            if(i==-1)
                return p;
            else if(i==n)
                return 1-p;

        }

    return 0;

}

int main(){

    cin>>n>>q>>s;
    for(int i=1;i<=q;i++)
        cin>>t[i]>>d[i];

    for(int p=1;p>=0;p--){

        int s,d,m;

        s=0;
        d=n-1;

        while(d-s>1){

            m=(s+d)/2;

            if(ok(m,p)) {

                s=p*m+(1-p)*s;
                d=(1-p)*m+p*d;

            }
            else {

                s=(1-p)*m+p*s;
                d=p*m+(1-p)*d;

            }

        }

        if(ok(p*d+(1-p)*s,p))
            poz[p]=p*d+(1-p)*s;
        else if(ok((1-p)*d+p*s,p))
            poz[p]=(1-p)*d+p*s;
        else poz[p]=p*(-1)+(1-p)*n;

    }

    poz[0]=n-poz[0];
    poz[1]++;

    cout<<n-poz[0]-poz[1];

}
