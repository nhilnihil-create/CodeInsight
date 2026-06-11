/*
* @Author: Kabid
* @Date:   {{create_time}}
* @Last Modified by:   Kabid
* @Last Modified time: 2020-09-19 16:18:14
*/
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define ll long long
#define  in(x) scanf("%d",&x);
#define out(x) printf("%d",x);
#define  ins(x)  scanf("%s",x);
#define outs(x) printf("%s",x);
#define lin puts("");
#define _ putchar(' ');

int t;       //test cases
ll i, j;	 //iterators
ll n, k , p, q,  d, m, c, c1, c2, d1,x; //variables;
ll mx = LLONG_MIN, mn = LLONG_MAX;		// max min
char s[6], s1, s2;		// string
ll a [1000001], b [200001] , mox [200001];	// array
map <int, int > mp;
vector <vector<ll>> vc;
vector <ll> v;
set <ll> st;
bool r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cin >> t; q = t;
	t = 1;
	
	while (t--) {


		/*cin >> s;
		n = s.size();
		for (i = n - 1; i > 0; i--) {
			for (j = i - 1; j >= 0; j--) {
				if (s[i] > s[j]) {
					swap(s[i], s[j]);
					cout << s << endl;
					break;
				}
			}
			if(j!=-1) break;
		}
		if (i == 0) {
			cout << "no answer" << endl;
		}*/
		cin>>n>>k;
		for(i=n;i<=k;i++){
			sprintf(s,"%d",i);
			for(j=0;j<=2;j++){
				if (s[j]!=s[5-j-1])
				{	
					//printf("%s\n",s );
					break;
				}
				
			}
			if(j==3){
				c++;
			}
			//cout<<s<<endl;
		}
		cout<<c<<endl;
	}


	return 0;

}