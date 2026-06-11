#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
long long upper,counter;
void solve(long long num,long long three,long long five,long long seven){
    if(num>upper){
        return;
    }
    if(three>=1&&five>=1&&seven>=1){
     counter++;
    }
    solve((num*10)+3,three+1,five,seven);
    solve((num*10)+5,three,five+1,seven);
    solve((num*10)+7,three,five,seven+1);
}
int main()
{
cin>>upper;
solve(0,0,0,0);
cout<<counter<<endl;



    return 0;
}
