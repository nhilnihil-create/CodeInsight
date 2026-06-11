#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M,a,onright,count,ans=0;
    cin >> N >> M;
    vector<int> k(M);
    vector<int> p(M);
    vector<vector<int>> s(M);
    std::vector<int>::iterator itr;
    for(int i=0;i<M;i++){
        cin >>k.at(i);
        for(int j=0;j<k.at(i);j++){
            cin >> a;
            s.at(i).push_back(a);
        }
    }   
    for(int i=0;i<M;i++)
        cin >> p.at(i);
    

    for (int bit = 0; bit < (1<<N); ++bit) {
        vector<int> S;
        count=0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i+1);
            }
        }
        for(int i=0;i<M;i++){
            onright=0;
            for (int j = 0; j < (int)S.size(); ++j) {
                itr = std::find(s.at(i).begin(), s.at(i).end(), S.at(j));
                if(itr == s.at(i).end()){
                }
                else{
                    onright++;
                }
            }
            if(onright%2==p.at(i))
                count++; 
        }
        if(count==M)
            ans++;
    }

    cout << ans <<endl;

}