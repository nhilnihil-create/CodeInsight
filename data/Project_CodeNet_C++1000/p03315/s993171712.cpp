#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int even=0;

    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+')
            even++;
        else
            even--;
    }
    cout<<even<<endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

    solve();

  return 0;
}
