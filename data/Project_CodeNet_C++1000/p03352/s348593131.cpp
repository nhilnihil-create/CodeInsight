#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int x;cin>>x;
    if(x==1){
        cout<<1<<endl;
        return 0;
    }
    
    while(true){
        int q = sqrt(x);
        for(int i = q;i>1;--i){
        int t=x;
        while(t>1){
            if(t%i==0)t/=i;
            else break;
            
            if(t==1){
                cout<<x<<endl;
                return 0;
            }
        }
        }
        --x;
        }
	return 0;
}