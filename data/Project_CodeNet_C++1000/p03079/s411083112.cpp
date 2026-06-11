#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int mod=1e9+7;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b&&b==c){
    cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
