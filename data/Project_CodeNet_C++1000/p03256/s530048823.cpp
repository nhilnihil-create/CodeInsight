#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    string ab;
    int ai, bi;
    cin >> N >> M;
    cin >> ab;
    map<int, map<int, int>> mat;
    for(int i=0;i<M;i++){
        cin >> ai >> bi;
        if(mat.count(ai-1)==0) mat[ai-1] = map<int, int>();
        if(mat.count(bi-1)==0) mat[bi-1] = map<int, int>();
        mat[ai-1][bi-1] = ab[bi-1]=='A'? 1:2;
        mat[bi-1][ai-1] = ab[ai-1]=='A'? 1:2;
    }
    set<int> goodV;
    queue<int> checkList;
    for(auto m : mat){ goodV.insert(m.first); }
    for(auto m : mat){ checkList.push(m.first); }
    while(!(checkList.empty())){
        int i = checkList.front();
        checkList.pop();
        bool haveA = false;
        bool haveB = false;
        if (mat.count(i)==0) continue;
        for(auto itr2=mat[i].begin();itr2 != mat[i].end(); itr2++){
            if((*itr2).second==1) haveA = true;
            if((*itr2).second==2) haveB = true;
        }
        if ( !(haveA && haveB) ){
            goodV.erase(i);
            vector<int> eraseList;
            for(auto itr2=mat[i].begin();itr2 != mat[i].end(); itr2++){
                int j = (*itr2).first;
                checkList.push(j);
                //mat[j].erase(i);
                eraseList.push_back(j);
            }
            for(auto iE : eraseList) mat[iE].erase(i);
            mat.erase(i);
        }
    }
    if(goodV.size()!=0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
