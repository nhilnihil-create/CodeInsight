#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int f(int i){
    if(i%2==0){
        return i/2;
    }else{
        return i*3+1;
    }
}
int main() {
    int s;
    cin>>s;
    vector<int>A(1000000);
    bool a=true;
    int ans=1;
    A[s]++;
    while(a==true){
        int b=f(s);
      ans++;
        if(A[b]!=0){
            a=false;
            cout<<ans<<endl;
        }
        else{
            A[b]++;
          s=b;
        }
    }
}