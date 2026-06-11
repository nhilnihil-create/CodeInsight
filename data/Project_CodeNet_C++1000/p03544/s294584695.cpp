#include <bits/stdc++.h>
using namespace std;

int64_t Lucus(int N);
bool exist(int N);

vector<int64_t> L{2,1};

int main(){
    int N;
    cin >> N;

    cout << Lucus(N) << endl;

    return 0;
}

//コメントアウトしているところは愚直な実装(ただの再帰)．
int64_t Lucus(int N){
    if(N == 0){
        //return 2;
        return L[0];
    }
    else if(N == 1){
        //return 1;
        return L[1];
    }
    else{
        //return Lucus(N-2) + Lucus(N-1);
        if(!exist(N-2)){
            L.push_back(Lucus(N-2));
        }
        if(!exist(N-1)){
            L.push_back(Lucus(N-1));
        }
        return L[N-2] + L[N-1];
    }
}

bool exist(int N){
    return (L.size() >= N+1);
}