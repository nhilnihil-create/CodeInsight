#include<bits/stdc++.h>
#define bye return 0
#define Yes cout << "Yes" << "\n"
#define No  cout << "No" << "\n"
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    set<int> s;
    int t, a, b, c, cnt=0;
    string st1;
    string st2;
    cin >> st1;
    cin >> st2;

    reverse(st1.begin(), st1.end());

    if(st1.compare(st2) == 0){
    	YES;
    }else{
    	NO;
    }

   bye;

}