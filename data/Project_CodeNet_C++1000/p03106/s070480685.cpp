		#include<bits/stdc++.h>
		#include<unordered_map>	
		#include<unordered_set>
		#define pb emplace_back
		#define rt(v) return cout<<v,0
		#define sz(v) (int)(v.size())
		#define all(a) a.begin(),a.end()
		#define endl '\n'
		#define space " "
		typedef long long ll;
		typedef unsigned long long ull;
		const int N = 10 + 1e5;
		const int mod = 1e9 + 7;
		/*

		███╗   ███╗███████╗███╗   ███╗███████╗    ██╗      ██████╗ ██████╗ ██████╗
		████╗ ████║██╔════╝████╗ ████║██╔════╝    ██║     ██╔═══██╗██╔══██╗██╔══██╗
		██╔████╔██║█████╗  ██╔████╔██║█████╗      ██║     ██║   ██║██████╔╝██║  ██║
		██║╚██╔╝██║██╔══╝  ██║╚██╔╝██║██╔══╝      ██║     ██║   ██║██╔══██╗██║  ██║
		██║ ╚═╝ ██║███████╗██║ ╚═╝ ██║███████╗    ███████╗╚██████╔╝██║  ██║██████╔╝
		╚═╝     ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝

		*/
		//
		int m1[150][150];
		int m2[150][150];
		using namespace std;
		void Ferrari() {
			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		}
	
		int main() {
			Ferrari();
			vector<int>divs;
			int a, b, k; cin >> a >> b >> k;
			for (int i = 1; i * i <= a; ++i) {
				if (a % i == 0)
				{
					divs.push_back(i);
					if (a / i != i) divs.push_back(a / i);
				}
			}
			sort(all(divs));
			vector<int>com;
			for (int i = 1; i * i <= b; ++i) {
				if (b % i == 0) {
					if (binary_search(all(divs), i))
						com.push_back(i);
					if (b / i != i)
						if (binary_search(all(divs), b / i))
							com.push_back(b / i);
				}
			}
			sort(all(com), greater<int>());
			cout << com[k - 1];
			return 0;
		}
		   

	


		/* stuff you should look for
			* keepin sharp mind.
			* int overflow, array bounds.
			* special cases (n=1?), set tle , make sure you understand the proble correctly.
			* don`t stuck in a problem.
			* test the idea on samples.
			*/