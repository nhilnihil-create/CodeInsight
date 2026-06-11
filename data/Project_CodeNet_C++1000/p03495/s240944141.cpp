#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N+10,0);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    
    vector<int> res(N+10, 0);
    int alltot=0;
    for(int i=0; i<N; i++){
        res.at(A.at(i))++;
    }
        sort(res.begin(), res.end(), greater<int>());
    for(int i=0; i<N; i++){
        alltot+=res.at(i);
    }
    

    int tot=0;
    for(int i=0; i<K; i++){
        tot+=res.at(i);
    }
    
    //cout << "alltot=" << alltot << " tot=" << tot << endl;
    
    //for(int i=0; i<N; i++){
        //cout << i << " " << res.at(i) << endl;
    //}
    
    cout << alltot - tot << endl;
    return 0;
}