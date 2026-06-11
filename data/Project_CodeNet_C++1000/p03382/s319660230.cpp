#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max = a[0];

    for(int i = 1; i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    
    int h = max/2;


    
    int dist = ((max != a[0])?
                            (a[0] <= max/2? a[0] : max - a[0]):
                            (a[1] <= max/2? a[1] : max - a[1]));
    int result = max != a[0]?
                            a[0] :a[1] ;

    for(int i = 1; i < n; i++){
        if(a[i] <= max/2){
            if(dist < a[i]){
                dist = a[i];
                result = a[i];
            }
        }else{
            int tmp = max - a[i];
            if(dist < tmp){
                dist = tmp;
                result = a[i];
            }
        }
    }

    cout << max << " ";
    cout << result << endl;

    return 0;
}