
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#define bye return 0
#define speedOne ios::sync_with_stdio(false)
#define speedtwo cin.tie(0)
typedef long long int lli;
typedef long long ll;
using namespace std;
int main()
{   
    speedOne;
    speedtwo;
	int cnt=0, t, m, n, x, y, a, b;
	cin >> m >> n >> x >> y;
	//set<int> s;
	//map<int, int> m;
	vector<int> xn;
	vector<int> yn;
	while(m--){
	    cin >> a;
	    xn.push_back(a);
	}
	while(n--){
	    cin >> b;
	    yn.push_back(b);
	}
	
	int max = *max_element(xn.begin(), xn.end());
	int min = *min_element(yn.begin(), yn.end());
	
	if(min>max && min>x && min<=y) cout << "No War" << "\n";
	else cout << "War" << "\n";
	
	bye;
}