#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    if(!( (N-1)/A + 1 <= B && B <= N - A + 1 )){
        cout << -1 << endl;
        return 0;
    }
    vector<int> vec;
    int x = N - A;
    int b = B - 1;
    while(x != 0){
        if(x - A >= b - 1){
            vec.push_back(A);
            x -= A;
            b--;
        }else{
            int a = x - b + 1;
            vec.push_back(a);
            b--;
            for(int i=0; i<b; i++)
                vec.push_back(1);
            break;
        }
    }
    vector<int> ans;
    for(int i=N-A+1; i<=N; i++) ans.push_back(i);
    int mx = N - A;
    for(int i=0; i<vec.size(); i++){
        int mn = mx - vec[i] + 1;
        for(int j=mn; j<=mx; j++) ans.push_back(j);
        mx = mn - 1;
    }
    for(auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}