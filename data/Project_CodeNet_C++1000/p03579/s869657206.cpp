#include <iostream>
#include <vector>

using namespace std;

vector<int> colour;
vector<vector<int> > e;

bool dfs(int v, int prev_col) {
    // cout <<"v, prev_col = " << v << ", " << prev_col << endl;
    if(colour[v]==0) {
        if(prev_col==1) {
            colour[v]=-1;
            for(int vi=0; vi<e[v].size(); vi++) {
                if(dfs(e[v][vi], -1)) {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        } else {
            colour[v]=1;
            for(int vi=0; vi<e[v].size(); vi++) {
                if(dfs(e[v][vi], 1)) {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        }
    } else if(colour[v]!=prev_col) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    colour = vector<int> (N, 0);
    
    e = vector<vector<int> >(N);
    for(int m=0; m<M; m++) {
        int A, B;
        cin >> A >> B;
        e[A-1].push_back(B-1);
        e[B-1].push_back(A-1);
    }
    
    bool is2g=false;
    // for(int v=0; v<N; v++) {
    //     if(colour[v]!=-1) {
    //         continue;
    //     }
    //     if(dfs(v, 1)) {
    //         is2g = true;
    //     }
    // }
    if(dfs(0, 1)) {
        is2g = true;
    }

    // for(int i=0; i<N; i++) {
    //     cout << colour[i] << endl;
    // }
    int B=0;
    for(int i=0; i<N; i++) {
        if(colour[i]==1) B++;
    }
    
    if(is2g) {
        // cout << "aaaa" << endl;
        cout << ((long long int)B)*((long long int)N-(long long int)B) - (long long int)M << endl;
    } else {
        cout << (long long int)N*(long long int)(N-1)/2 - M << endl;
    }

    return 0;
    
}