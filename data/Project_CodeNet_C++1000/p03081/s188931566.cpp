#include <iostream>
using namespace std;

const int maxN=2e5+1;

int n,q;
char str[maxN];
char t[maxN];
char d[maxN];

bool good(bool type,int pos){
    for(int i=1;i<=q;i++){
        if(t[i]==str[pos]){
            if(d[i]=='L'){
                pos--;
            } else {
                pos++;
            }
        }
        if(type && pos==n+1){
            return 1;
        } else if(pos==0){
            return 1;
        }
    }

    return 0;
}

int main(){
    cin>>n>>q>>(str+1);
    for(int i=1;i<=q;i++){
        cin>>t[i]>>d[i];
    }

    int st=0,dr=n;
    int sol1=0;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(good(0,mij)){
            sol1=mij;
            st=mij+1;
        } else {
            dr=mij-1;
        }
    }

    int sol2=n+1;
    st=0,dr=n+1;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(good(1,mij)){
            sol2=mij;
            dr=mij-1;
        } else {
            st=mij+1;
        }
    }

    if(sol1<sol2){
        cout<<sol2-sol1-1;
    } else {
        cout<<0;
    }

    return 0;
}