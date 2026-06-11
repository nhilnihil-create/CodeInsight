#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const ll inf=1e9+7;

int main(){

    string s;
    cin >> s;

    if(s == "KIHBR") cout << "YES" << endl;
    else if(s == "KIHBRA") cout << "YES" << endl;
    else if(s == "KIHBAR") cout << "YES" << endl;
    else if(s == "KIHBARA") cout << "YES" << endl;
    else if(s == "KIHABR") cout << "YES" << endl;
    else if(s == "KIHABRA") cout << "YES" << endl;
    else if(s == "KIHABAR") cout << "YES" << endl;
    else if(s == "KIHABARA") cout << "YES" << endl;
    else if(s == "AKIHBR") cout << "YES" << endl;
    else if(s == "AKIHBRA") cout << "YES" << endl;
    else if(s == "AKIHBAR") cout << "YES" << endl;
    else if(s == "AKIHBARA") cout << "YES" << endl;
    else if(s == "AKIHABR") cout << "YES" << endl;
    else if(s == "AKIHABRA") cout << "YES" << endl;
    else if(s == "AKIHABAR") cout << "YES" << endl;
    else if(s == "AKIHABARA") cout << "YES" << endl;
    else cout <<"NO" << endl;
}