#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main() {
    int n;cin>>n;
    int a[4];
    rep(i,4){
        a[3-i]=n%10;
        n/=10;
    }
    int ans = 7 - a[0];
//    int tmp;
    char s1,s2,s3;

    rep(i,2){
        rep(j,2){
            rep(k,2){
        int tmp = 0;
            if(i==0){
                tmp+=a[1];
                s1 = '+';
            }
            else {
                tmp-=a[1];
                s1 = '-';
            }


           if(j==0){
                tmp+=a[2];
                s2 = '+';
            }
            else {
                tmp-=a[2];
                s2 = '-';
            }

           if(k==0){
                tmp+=a[3];
                s3 = '+';
            }
            else {
                tmp-=a[3];
                s3 = '-';
            }

             if(tmp==ans){
                cout<<a[0]<<s1<<a[1]<<s2<<a[2]<<s3<<a[3]<<"=7"<<endl;
                return 0;
            }              
             else tmp = 0;

            }
        }
    }
    
	return 0;
}

