#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    int a,b;
    cin >> a >> b;

    if(a%2==0||b%2==0){
        puts("No");
        return 0;
    }
    puts("Yes");

    return 0;
}