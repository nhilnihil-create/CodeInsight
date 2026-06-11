#include<bits/stdc++.h>
using namespace std;

#define loop(n) for(int i = 0;i < (int)(n);++i)
#define rep(i,n) for(int i = 0;i < (int)(n);++i)
#define all(vec) (vec).begin(),(vec).end()
#define Sort(vec) sort(all(vec))
#define Rev(vec) reverse(all(vec))

using Graph = vector<vector<int>>;

namespace Input
{
                
    void input(){return;}
    template<typename First,typename... Rest> void input(First &first,Rest&... rest){
    std::cin >> first;
    input(rest...);
}
    
    void inputVec(){return;}
    template<typename First,typename... Rest> void inputVec(vector<First> &first,Rest&... rest){
        int N = first.size();
        for(int i = 0;i < N;i++){
            cin >> first[i];
        }
        inputVec(rest...);
    }
    
    template<typename First,typename Second> void inputTwoVec(vector<First> &first,vector<Second>& second){
        int N = first.size();
        for(int i = 0;i < N;i++){
            cin >> first[i] >> second[i];
        }
    }

    void inputGraph(Graph &g,int path_num,bool isdirected){
        for(int i = 0;i < path_num;i++){
            int a,b;
            cin >> a >> b;
            a--;b--;
            if(isdirected){
                g[a].push_back(b);
            }
            else{
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
    }
}

void calculate(){
    int N,K;
    Input::input(N,K);
    map<int,int> m;
    int tmp;
    int kind = 0;
    rep(i,N){
        cin >> tmp;
        if(m.count(tmp) == 0){
            m.insert(make_pair(tmp,1));
            kind++;
        }
        else{
            m[tmp]++;
        }
    }
    if(kind <= K){
        cout << 0 << '\n';
        return;
    }
    vector<int> l;
    for(auto i : m){
        l.push_back(i.second);
    }
    Sort(l);
    int res = 0;
    rep(i,N){
        if(kind == K){
            cout << res << '\n';
            return;
        }
        else{
            res += l[i];
            kind--;
        }
    }
    cout << res << '\n';
}

int main(int,char**){
    calculate();    
}


