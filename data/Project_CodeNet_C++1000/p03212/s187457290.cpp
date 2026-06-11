#include <iostream>
using namespace std;
long long N;
void dfs(long long x,int bits, long long &cnt){
    if(x>N) return;
    if(bits==0b111) cnt++;
    dfs(x*10+3,bits|0b001,cnt);
    dfs(x*10+5,bits|0b010,cnt);
    dfs(x*10+7,bits|0b100,cnt);
}
int main(void){
    long long ans=0;
    cin >> N;
    dfs(0,0,ans);
    cout <<  ans << endl;
}