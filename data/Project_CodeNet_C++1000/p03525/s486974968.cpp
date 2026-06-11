#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> D;
    for(int i=0;i<N;i++){
        int t;
        cin >>t;
        D.push_back(t);
    }
    vector<int> T(13,0);
    T[0]++;
    for(int i=0;i<D.size();i++){
        T[D[i]]++;
    }
    for(int i=0;i<13;i++){
        if(T[i]>2){
            cout << 0<<endl;
            return 0;
        }
    }
    if(T[0]>=2){
        cout << 0 << endl;
        return 0;
    }

    int ans=0;
    for(int bit=0;bit<(1<<12);bit++){
        vector<int> A;
        A.push_back(0);
        for(int i=0;i<12;i++){
            if(T[i+1]==2){
                A.push_back(i+1);
                A.push_back(23-i);
            }
            else if(T[i+1]==1){
                if(bit&(1<<i)){
                    A.push_back(23-i);
                }
                else{
                    A.push_back(i+1);
                }
            }
        }
        int C=100;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A.size();j++){
                if(i==j)continue;
                int dt = abs(A[i]-A[j]);
                dt = min(dt,24-dt);
                C = min(C,dt);
            }
        }
        ans = max(ans,C);
    }
    cout << ans <<endl;
}
