#include <bits/stdc++.h>
#define pb push_back
#define vt vector
#define ll long long
using namespace std;

const int INF = 1e9 +5;
const ll LLINF = 1e18 +5;

int i4[4] = {1,0,-1,0};
int j4[4] = {0,1,0,-1};


void solve()
{
	int n;
	cin >>n;
    vt<pair<int,pair<int,int>>> v;
    for(int i = 0;i < n;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,{b,c}});
    }
    sort(v.begin(),v.end());
    int lastX = 0, lastY =0, lastTime = 0;
    for(int i = 0; i < n;i++)
    {
        auto cur = v[i];
        int curTime = cur.first;
        int curX = cur.second.first;
        int curY = cur.second.second;
        int dist = abs(lastX-curX) + abs(lastY-curY);
        int timeDif = curTime - lastTime;
        if(timeDif < dist || timeDif%2!=dist%2)
        {
            cout << "No" << endl;
            return;
        }
        lastX = curX;
        lastY = curY;
        lastTime = curTime;
    }
        cout << "Yes" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();

  return 0;
}
