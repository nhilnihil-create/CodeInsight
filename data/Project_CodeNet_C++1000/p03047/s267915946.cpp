//************************
//** author  :  Alex Hu **
//************************

//  _______        __________         ________        __
//  \      \   ____\______   \ ____  /  _____/  _____/  |_
//  /   |   \ /  _ \|       _// __ \/   \  ____/ __ \   __\
// /    |    (  <_> )    |   \  ___/\    \_\  \  ___/|  |
// \____|__  /\____/|____|_  /\___  >\______  /\___  >__|
//         \/              \/     \/        \/     \/

#include<bits/stdc++.h>

using namespace std;

#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define pb push_back
#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define fi first
#define se second
#define sqr(a) ((a)*(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod=1e9+7;
const int INF=0x3f3f3f3f; 
const int MAX=2e5+5;

int n,k; 

int main()
{
	cin>>n>>k;
	cout<<n-k+1<<endl;
	return 0;
}