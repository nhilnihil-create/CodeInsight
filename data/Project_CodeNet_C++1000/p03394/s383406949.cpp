#include<bits/stdc++.h>
using namespace std;
int n,ans[8];
int main()
{
    cin >> n;
    if (n == 3){
        cout << "2 5 63";
    }
    else{
    if(n % 2 == 1)
        ans[0]=6,ans[1]=2,ans[2]=10,ans[3]=3,ans[4]=9,ans[5]=4,ans[6]=8,ans[7]=12;
    else
        ans[0]=2,ans[1]=10,ans[2]=3,ans[3]=9,ans[4]=4,ans[5]=8,ans[6]=6,ans[7]=12;
    for(int i = 0; i < min(8 , n); i++) cout << ans[i] << " ";
    for(int i = 8; i < n; i++) ans[i % 8] += 12 , cout << ans[i%8] << " ";
    return 0;}
}
