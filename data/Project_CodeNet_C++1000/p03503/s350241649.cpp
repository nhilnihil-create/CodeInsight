#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

template<typename T>
void cout_mat(vector<vector<T>  > &mat){
    for(int i=0; i<mat.size(); i++){
        vector<T> vec = mat[i];
        cout_vec(mat[i]);
    }
}

ll calc(vector<int> vec, vector<vector<int>> &F, vector<vector<ll>> &P){
    int cnt=0;
    ll ans=0;
    for(int i=0; i<(int)F.size(); i++){
        int tmp=0;
        for(int j=0; j<10; j++){
            cnt+=vec[j];
            tmp+=vec[j]&F[i][j];
        }
        ans+=P[i][tmp];
    }
    if(cnt==0){
        return -MOD*MOD;
    }else{
        return ans;
    }
}

ll full_search(vector<int> &vec,vector<vector<int>> &F, vector<vector<ll>> &P){
    if((int)vec.size()==10){
        return calc(vec, F, P);
    }

    ll ret=-MOD*MOD;

    vec.push_back(1);
    ret=max(ret,full_search(vec, F, P));
    vec.pop_back();
    
    vec.push_back(0);
    ret=max(ret,full_search(vec, F, P));
    vec.pop_back();

    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> F(N,vector<int>(10,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<2; k++){
                cin >> F[i][j*2+k];
            }
        }
    }

    vector<vector<ll>> P(N,vector<ll>(11,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<11; j++){
            cin >> P[i][j];
        }
    }

    //cout_mat(P);
    //cout_mat(F);

    vector<int> vec(0);
    cout << full_search(vec, F, P) << endl;
}