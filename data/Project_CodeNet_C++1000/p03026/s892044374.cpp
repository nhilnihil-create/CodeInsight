#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <queue>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

class Tree{
public:
    Tree(long long int tree_size):nodes(tree_size,-1),parent(tree_size){

    }
    void add_edge(long long int a,long long int b){
        parent[a].push_back(b);
        parent[b].push_back(a);
    }

    void habatan(vector<long long int> v){
        queue<long long int> q;
        long long int loop=0;
        q.push(0);
        
        while(!q.empty()){
            nodes[q.front()] = v[loop];
            
            loop++;
            for(auto x:parent[q.front()]){
                if(nodes[x]==-1){
                    q.push(x);
                }
            }
            q.pop();
        }
    }
    void print(){
        REP(i,nodes.size()-1){
            cout << nodes[i] << " ";
        }
        cout << nodes[nodes.size() - 1] << endl;
    }
private:
    vector<long long int> nodes;
    vector<vector<long long int>> parent;
};

int main(){

    long long int n;
    cin >> n;
    long long int tmpa, tmpb;
    Tree tree(n);
    REP(i,n-1){
        cin >> tmpa >> tmpb;
        tree.add_edge(tmpa-1, tmpb-1);
    }
    vector<long long int> cv(n);
    REP(i,n){
        cin >> cv[i];
    }
    sort(cv.begin(), cv.end(), greater<long long int>());
    long long int sum = 0;
    FOR(i,1,n){
        sum += cv[i];
    }
    cout << sum << endl;
    tree.habatan(cv);
    tree.print();

    return 0;
}
