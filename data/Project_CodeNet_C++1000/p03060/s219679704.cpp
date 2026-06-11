#include <bits/stdc++.h>

using namespace std;

// 10進数⇒base進数, digit桁目を取得(0桁目~) 計算量O(N)
template <typename type>
type BaseChange(type num, type base, type digit)
{
    for(type i=0;i<digit;i++) num/=base;        
    return num%base;
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(n),v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> c[i];

    int ans=-1;
    for(int i=0;i<(1<<n);i++){
        int x=0,y=0;
        for(int j=0;j<n;j++){
            if(BaseChange(i,2,j)){
                x+=v[j];
                y+=c[j];
            }
        }
        ans=max(ans,x-y);
    }
    cout << ans << endl;
}