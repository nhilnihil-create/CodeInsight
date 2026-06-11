#include<bits/stdc++.h>
#define bye return 0
#define Yes cout << "Yes" << "\n"
#define No  cout << "No" << "\n"
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define endl cout << "\n"
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> xa;
    vector<int> ya;
    int x, y, m, n, cnt=0, a, b;
    cin >> n >> m >> x >> y;

    for(int i=0; i<n; ++i){
    	cin >> a;
    	xa.push_back(a);
    }

    for(int i=0; i<m; ++i){
    	cin >> b;
    	ya.push_back(b);
    }

    sort(xa.begin(), xa.end());
    sort(ya.begin(), ya.end());
    int lx=xa.size();
    //int ly=ya.size();

    //cout << xa[lx-1] << " " << ya[ly-1] << "\n";

    if(ya[0] > xa[lx-1] && ya[0] > x && ya[0] <=y) cout << "No War" << "\n";
    else cout << "War" << "\n";


   /*for(auto i:xa) cout << i << " ";
   	endl;
   for(auto i:ya) cout << i << " ";*/
    

   bye;
    
}