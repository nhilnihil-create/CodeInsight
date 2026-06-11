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

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    int sr, sc;
    cin >> sr >> sc;
    string S, T;
    cin >> S >> T;

    vector<vector<int> > dpLR(N+1,vector<int>(2,0));
    dpLR[N]={1,W};
    vector<vector<int> > dpUD(N+1,vector<int>(2,0));
    dpUD[N]={1,H};

    for(int i=N; i>0; i--){
        if(T[i-1]=='L'){
            dpLR[i][1]=min(W, dpLR[i][1]+1);
        }else if(T[i-1]=='R'){
            dpLR[i][0]=max(1, dpLR[i][0]-1);
        }else if(T[i-1]=='U'){
            dpUD[i][1]=min(H, dpUD[i][1]+1);
        }else if(T[i-1]=='D'){
            dpUD[i][0]=max(1, dpUD[i][0]-1);
        }

        if(S[i-1]=='L'){
            dpLR[i-1][0]=dpLR[i][0]+1;
            dpLR[i-1][1]=dpLR[i][1];
            dpUD[i-1]=dpUD[i];
        }else if(S[i-1]=='R'){
            dpLR[i-1][1]=dpLR[i][1]-1;
            dpLR[i-1][0]=dpLR[i][0];
            dpUD[i-1]=dpUD[i];
        }else if(S[i-1]=='U'){
            dpUD[i-1][0]=dpUD[i][0]+1;
            dpUD[i-1][1]=dpUD[i][1];
            dpLR[i-1]=dpLR[i];
        }else if(S[i-1]=='D'){
            dpUD[i-1][1]=dpUD[i][1]-1;
            dpUD[i-1][0]=dpUD[i][0];
            dpLR[i-1]=dpLR[i];
        }

        //cout << i << ' ' << endl;;
        //cout_vec(dpLR[i-1]);
        //cout_vec(dpUD[i-1]);

        if(dpLR[i-1][0]>dpLR[i-1][1]){
            cout << "NO" << endl;
            return 0;
        }else if(dpUD[i-1][0]>dpUD[i-1][1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(dpLR[0][0]<=sc && sc<=dpLR[0][1] && dpUD[0][0]<=sr && sr<=dpUD[0][1]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}