#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 1e5 + 5;

ll largest(ll a, ll b){
	return (a<b)?b:a;
}
ll smallest(ll a, ll b){
	if(a < b)return a;
	return b;
}

int main(){
	int c[3][3];
	int a[3];
	int b[3];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> c[i][j];
		}	
	}
	for(a[0] = 0; a[0] <= 100; a[0]++){
		for(a[1] = 0; a[1] <= 100; a[1]++){
			for(a[2] = 0; a[2] <= 100; a[2]++){
				b[0] = c[0][0] - a[0];
        		b[1] = c[0][1] - a[0];
        		b[2] = c[0][2] - a[0];
        		bool correct = true;
        		for(int i = 0; i < 3; ++i){
        			for(int j = 0; j < 3; ++j){
        				if(c[i][j] != a[i] + b[j]){
        					correct = false;
        				}
         			}
        		}
        		if(correct){
        			cout << "Yes" << endl;
        			return 0;
        		}
			}
		}
	}
	cout << "No" << endl;

    return 0;
}
