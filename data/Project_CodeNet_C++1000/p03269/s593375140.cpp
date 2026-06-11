#include <iostream>
#include <vector>

struct edge{
    int from;
    int to;
    int cost;
};

using namespace std;

int pow(int n, int k){
    int ans = 1;
    for(int i = 0; i < k; i++){
        ans *= n;
    }
    return ans;
}

int main(){
    int L;
    vector<edge> es;
    cin >> L;
    int tmp = 1, cnt = 0;
    while(L >= tmp){
        tmp *= 2;
        cnt++;
    }
    for(int i = 1; i < cnt ; i++){
        edge edge1 = {i, i+1, 0};
        edge edge2 = {i, i+1, pow(2, i-1)};
        es.push_back(edge1);
        es.push_back(edge2);
    }
    tmp = pow(2, cnt-1);
    if(L%2 == 1){
        edge edge1 = {1, cnt, tmp};
        es.push_back(edge1);
        tmp+= 1;
        L = (L - 1)/2;
    }else{
        L = L/2;
    }
    for(int i = 2; i < cnt; i++){
        if(L%2 == 1){
            edge edge1 = {i, cnt, tmp};
            es.push_back(edge1);
            tmp+= pow(2, i-1);
        }
        L = (L - (L%2))/2;
    }
    cout << cnt << ' ' << es.size() << endl;
    for(int i = 0; i < es.size(); i++){
        cout << es[i].from << ' ' << es[i].to << ' ' << es[i].cost << endl;
    }
}