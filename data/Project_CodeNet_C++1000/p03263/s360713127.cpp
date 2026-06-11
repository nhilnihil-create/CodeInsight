
 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define pi pair<ll,ll>
#define ff first
#define ss second
#define MAX 100005
const ll MOD = 1000000007;

struct an{
	int sy,sx,gy,gx;
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t=1;
//	cin>>t;
	while(t--){
	int h,w;
	cin>>h>>w;
	int a[h+5][w+5];

	for(int i=0;i<h;i++)
	{
	   for(int j=0;j<w;j++)
	   cin>>a[i][j];
	}
	w--;
	vector<an>ans;

	for(int i=0;i<h;i++)
	{
		 for(int j=0;j<w;j++)
		 {
		 	if(a[i][j]%2==0) continue;
		 	a[i][j+1]++;
		 	ans.pb({i+1,j+1,i+1,j+2});
		 }
		 if(i>=h-1 || a[i][w]%2==0) continue;
		 a[i+1][w]++;
		 ans.pb({i+1,w+1,i+2,w+1});
	}


	cout<<ans.size()<<endl;
	for(auto i:ans)
	{
		cout<<i.sy<<" "<<i.sx<<" "<<i.gy<<" "<<i.gx<<endl;
	}
	}
}





/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,k=0;
        cin>>n;
        int ar[n];
        for(i=0;i<n;i++)
            cin>>ar[i];
            for(i=1;i<n-1;i++)
            {
                if(ar[i-1]>ar[i]&&ar[i]<ar[i+1])
                    k=i;
            }
            cout<<k<<endl;
    }
}*/
