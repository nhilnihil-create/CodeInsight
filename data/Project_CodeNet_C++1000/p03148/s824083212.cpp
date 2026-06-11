#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0; i<n; i++)

struct sushi
{
  ll type;
  ll val;

  sushi(ll t, ll d)
  {
    type = t;
    val = d;
  }
};

void print_vec(vector<sushi> v)
{
  for(auto itr = v.begin(); itr!=v.end(); itr++)
  {
    cout <<(*itr).type << " " << (*itr).val << endl;
  }
}

void print_que(priority_queue<ll,vector<ll>,greater<ll> > que)
{
  cout << "queue:";
  priority_queue<ll,vector<ll>,greater<ll> > p = que;
  while(!p.empty())
  {
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;
}


int main()
{
  ll n,k;
  cin >> n >> k;

  vector<sushi> v;
  rep(n)
  {
    ll t,d;
    cin >> t >> d;
    v.emplace_back(sushi(t,d));
  }

  auto cmp = [](sushi left, sushi right) {return left.val > right.val;};
  sort(v.begin(),v.end(),cmp);

  priority_queue<ll,vector<ll>,greater<ll> > que;
  vector<bool> flag(n+1,0);
  
  ll cur = 0, tmp_del = 0;
  for (cur = 0; cur < k; cur++)
  {
    sushi s = v[cur];
    if(flag[s.type])
    {
      que.push(s.val);
    } else {
      flag[s.type] = 1;
    }
    tmp_del += s.val;
  }
  
  ll var = 0;
  for (ll i = 1; i < n+1; i++)
  {
    var += (ll)flag[i];
  }
  ll tmp = tmp_del + var*var;

  sushi s = v[cur];
  while( var <= n )
  {
    var++;
    if(que.empty()) break;
    while(flag[s.type]){
      cur++;
      if(cur==n) break;
      s = v[cur];
    }
    if(cur==n) break;

    flag[s.type] = 1;
    tmp_del = tmp_del + s.val - que.top();
    que.pop();
    tmp = max(tmp, tmp_del + var*var);
  }

  cout << tmp << endl;
  

  return 0;
}