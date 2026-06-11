#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<map>
#include<stack>
#include<bits/stdc++.h>
#include<string.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
//#define f first
//#define s second
#define respr(fir,sec) for(int i=0;i<=fir;i++){for(int j=0;j<=sec;j++){cout << res[i][j] << " ";}cout << "\n";}
#define pb push_back
//#define INF (1LL<<31)
using namespace std;
using namespace __gnu_pbds;
const int mod = 1e9+7;
const ll MAX = 1000000000000000000;
typedef pair<int,ll> pii;
typedef pair<ll,int> pi;
typedef tuple<long long,int> tp;
typedef tuple<int,int,long long> tu;
typedef multimap<pii , int> mpp;
typedef priority_queue< tp , vector<tp>, greater<tp>>  minheap;
typedef priority_queue<pii , vector<pii>> maxheap;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>  new_data_set;
const int maxi = 305;

double p[maxi][maxi][maxi];
double ev[maxi][maxi][maxi];

int main()
{
	FASTIO;
	int n;
	cin >> n ;
	vector<int> count(4);
	int temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		count[temp]++;
	}
	
	p[count[1]][count[2]][count[3]]=1;
	
	for(int c=n;c>=0;--c){
		for(int b=n;b>=0;--b){
			for(int a=n;a>=0;--a){
				
				if(a==0&&b==0&&c==0)
					continue;
				
				if(a+b+c>n)
					continue;
				
				double p_waste = (double)(n-(a+b+c))/n;
				
				double ev_waste = (double)p_waste/(1-p_waste);
				
				ev[a][b][c] += ev_waste*p[a][b][c];
				
				
				if(a!=0){
					double p_go = (double)(a)/(a+b+c);
					p[a-1][b][c] += p[a][b][c]*p_go;
					ev[a-1][b][c] += ev[a][b][c]*p_go;
				}
				
				if(b!=0){
					double p_go = (double)(b)/(a+b+c);
					p[a+1][b-1][c] += p[a][b][c]*p_go;
					ev[a+1][b-1][c] += ev[a][b][c]*p_go;
				}
				
				if(c!=0){
					double p_go = (double)(c)/(a+b+c);
					p[a][b+1][c-1] += p[a][b][c]*p_go;
					ev[a][b+1][c-1] += ev[a][b][c]*p_go;
				}
				
			}
		}
	}
	
	printf("%.13lf\n", ev[0][0][0]+(count[1]+2*count[2]+3*count[3]));
	//cout << ev[0][0][0]+(count[1]+2*count[2]+3*count[3]) << "\n";
	return 0;
}
