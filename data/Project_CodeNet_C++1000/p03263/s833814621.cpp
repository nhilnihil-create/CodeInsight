#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=1'000'000'007;
const double EPS=1e-14;
const bool DEBUG=true;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////


class Operation{
public:
    int y1, x1, y2, x2;
};

void answer(){
    int H, W;
    cin>>H>>W;

    vector<vector<int>> a(H, vector<int>(W));
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            cin>>a[i][j];
        }
    }

    int N=0;
    vector<Operation> ope;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W-1; ++j){
            if(a[i][j] & 1){
                ope.push_back({i, j, i, j+1});
                a[i][j]--;
                a[i][j+1]--;
                N++;
            }
        }
    }

    for(int i=0; i<H-1; ++i){
        if(a[i][W-1] & 1){
            ope.push_back({i, W-1, i+1, W-1});
            a[i][W-1]--;
            a[i+1][W-1]++;
            N++;
        }
    }

    cout<<N<<endl;
    for(int i=0; i<N; ++i){
        cout<<ope[i].y1+1<<" "<<ope[i].x1+1<<" "<<ope[i].y2+1<<" "<<ope[i].x2+1<<endl;
    }

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    answer();

    return 0;
}
