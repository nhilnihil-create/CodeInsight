#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int N,M,C;
    cin >> N >> M >> C;
    vector<int>vec;
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vector<int> vec2;
    int count =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int num;
            cin >> num;
            vec2.push_back(num);
        }
        int total = 0;
        for(int i=0; i<vec.size(); i++){
            total += vec[i]*vec2[i];
        }
        vec2.clear();
        if(total + C > 0){
            count++;
        }
    }
    cout << count <<endl;

}