#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
typedef vector<int> vr;
typedef pair<int, int> pr;
#define pb push_back
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
#define endl "\n"
//cout << fixed << setprecision(2);


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt1 = 0, cnt9 = 0, cnt7 = 0, cnt4 = 0;
    for(int i = 1; i <= 4; i++){
    	char a;
    	cin >> a;
    	if(a == '1'){
    		cnt1++;
    	}
    	else if(a == '9'){
    		cnt9++;
    	}
    	else if(a == '7'){
    		cnt7++;
    	}
    	else if(a == '4'){
    		cnt4++;
    	}
    }
    if(cnt1 == 1 && cnt9 == 1 && cnt7 == 1 && cnt4 == 1){
    	cout << "YES" << endl;
    }
    else{
    	cout << "NO" << endl;
    }
    return 0;
}
