#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int w,l;
char ch;
int main(){
	while(cin>>ch){
		if(ch=='x')l++;
	}
	w=15-l;
	cout<<(w>=8?"YES":"NO")<<endl;
	return 0;
}
