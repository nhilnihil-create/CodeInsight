#include <bits/stdc++.h>
 
#define pb push_back
#define ll long long
#define f first
#define s second     
using namespace std;
 
void scan()
{
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
 
}
const int N = 1e6 + 500;
const int mod = 1e9 + 7;
int ans[N];
int main() 
{
    scan();                 
    int n;
    cin >> n;
    pair<string, pair<int,int>> a[n + 1];
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i].f >> a[i].s.f;
    	a[i].s.s = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
    	ans[a[i].s.s] = i;
    //	cout << a[i].f << " " << a[i].s.f << " " << a[i].s.s << '\n';
    }
    stack<int> q;
    q.push(a[1].s.s);
    for (int i = 2; i <= n; i++)
    {
    	if (a[i].f != a[i - 1].f)
    	{
    		while (q.size() > 0)
    		{
    			cout << q.top() << '\n';
    			q.pop();
    		}
    	} 	
    	q.push(a[i].s.s);
    }
    while (q.size() > 0)
    		{
    			cout << q.top() << '\n';
    			q.pop();
    		}

}     
//JUDGE_ID: 295965SY
//Tis I