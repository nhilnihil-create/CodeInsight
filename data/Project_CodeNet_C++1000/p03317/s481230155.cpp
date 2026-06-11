#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n];
    for(auto &it:a)
        cin>>it;

    cout<<((n-3+k)/(k-1))<<endl;

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

    solve();

  return 0;
}
