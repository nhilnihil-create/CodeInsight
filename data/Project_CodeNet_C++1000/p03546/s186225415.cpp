#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

vector<vector<int>> c(10, vector<int>(10));

void floyd(){
    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                c[i][j]=min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
}


int main(){
    int h;
    int w;
    int ans=0;
    cin >> h >> w;
    int a;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> c[i][j];
        }
    }

    floyd();

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a;
            if(a!=-1){
                ans+=c[a][1];
            }
        }
    }

    //for(int i=0; i<10; i++){
    //    for(int j=0; j<10; j++){
    //        cout << c[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << ans << endl;

}
