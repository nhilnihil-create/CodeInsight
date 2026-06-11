#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int N;
    cin >> N;
    int A, B;
    cin >> A >> B;
    queue<int> P;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        P.push(tmp);
    }
    int x=0, y=0, z=0;
    while(!P.empty()){
        if(P.front()<=A){
            x++;
        }else if(P.front()<=B){
            y++;
        }else{
            z++;
        }
        P.pop();
    }
    cout << min(min(x,y),z);
}