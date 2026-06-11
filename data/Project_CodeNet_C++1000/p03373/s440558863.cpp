#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int ans=INF;
	fori(max(x,y)+1){
		int score=0;
		score+=i*2*c;
		if(x-i>0)score+=(x-i)*a;
		if(y-i>0)score+=(y-i)*b;
		ans=min(score,ans);
	}
	cout<<ans;
}