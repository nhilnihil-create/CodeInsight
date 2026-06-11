#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void print_vector(vector<ll> vt){
    for(auto v: vt){
        cout << v;
    }
    cout << endl;
}

int A,B;
int ans[100][100];

int main()
{
    cin >> A >> B;
    int h=100, w=100;
    A--; B--;
    memset(ans, 1, sizeof(ans));
    bool flag1=false, flag2=false;
    for(int i=0; i<h/2; i+=2){
        for(int j=0; j<w; j+=2){
            if(A==0){
                flag1=true;
                break;
            }
            ans[i][j]=0;
            A--;
        }
        if(flag1) break;
    }
    for(int i=h/2; i<h; i++){
        for(int j=0; j<w; j++){
            ans[i][j]=0;
        }
    }
    for(int i=h-1; i>=h/2; i-=2){
        for(int j=0; j<w; j+=2){
            if(B==0){
                flag2=true;
                break;
            }
            ans[i][j]=1;
            B--;
        }
        if(flag2) break;
    }
    cout << h << ' ' << w << endl;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(ans[i][j]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    

    return 0;
}
