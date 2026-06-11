#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;cin>>n;
    for(int i=n;i>=1;--i){
        int s =sqrt(i);
        if(s*s==i){
            cout<<i<<endl;
            return 0;
        }
    }
	return 0;
}