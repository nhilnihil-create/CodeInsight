#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 50;
int vis[maxn];
void init()
{
	vis[0] = 1;
	vis[1] = 1;
	for(int i = 2;i < maxn;i ++)
	{
		if(! vis[i])
		{
			vis[i] = 0;
			for(int j = 2*i;j < maxn; j += i)
			{
				vis[j] = 1;
			}
		}
	}
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    init();
    vector<int> ans;
    if(n % 2 == 0) ans.push_back(2),n --;
    for(int i = 3;i < maxn;i++){
        if(!vis[i] && i % 10 == 1){
            ans.push_back(i);
            n--;
        }
        if(n == 0) break;
    }
    for(int i = 0;i < ans.size();i++) {
        if(i == ans.size() - 1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    return 0;
}
