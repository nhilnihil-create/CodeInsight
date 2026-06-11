#include <bits/stdc++.h>
#define PI acos(-1.0)
#define mem(a,b) memset((a),b,sizeof(a))
#define TS printf("!!!\n")
#define pb push_back
#define inf 1e9
//std::ios::sync_with_stdio(false);
using namespace std;
//priority_queue<int,vector<int>,greater<int>> que; get min
const double eps = 1.0e-10;
const double EPS = 1.0e-4;
typedef pair<int, int> pairint;
typedef long long ll;
typedef unsigned long long ull;
const int turn[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
//priority_queue<int, vector<int>, less<int>> que;
//next_permutation
inline void read(int &jqk)
{
        jqk = 0;char c = 0;int p = 1;while (c < '0' || c > '9')
        {if (c == '-'){p = -1;}c = getchar();}
        while (c >= '0' && c <= '9'){jqk = (jqk << 3) + (jqk << 1) + c - '0';c = getchar();}jqk *= p;
}
ll mod=1e9+7;
stack<int> sta;
ll n,a,b;
int main()
{
        cin >> n >> a >> b;
        //cout<<a*b<<endl;
        if(a+b-1>n)
        {
                cout<<-1<<endl;
                return 0;
        }
        if(a*b<n)
        {
                cout<<-1<<endl;
                return 0;
        }
        int k=1;
        for(int i=1;i<=a;i++)
        {
                for(int j=1;j<=b&&a-i+k<=n;j++)
                {
                sta.push(k++);
                }
                while(!sta.empty())
                {
                        cout<<sta.top()<<" ";
                        sta.pop();
                }
        }
}
