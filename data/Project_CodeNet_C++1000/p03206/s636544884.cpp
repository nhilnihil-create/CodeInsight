#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define mem(i,a) memset(i,a,sizeof(i))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const ll INF=10000000000;
const int DMAX=600000+5;
const int MOD=6000000;
template<class T> inline void read(T &x){
    x=0; 
    T f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9' && ch>='0'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
int d;
int main(){
	cin>>d;
	if(d==25){
		cout<<"Christmas"<<endl;
	}
	if(d==24){
		cout<<"Christmas Eve"<<endl;
	}
	if(d==23){
		cout<<"Christmas Eve Eve"<<endl;
	}
	if(d==22){
		cout<<"Christmas Eve Eve Eve"<<endl;
	}
	return 0;
}