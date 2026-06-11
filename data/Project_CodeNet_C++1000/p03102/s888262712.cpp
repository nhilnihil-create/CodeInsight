#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,M,C;
    cin >> N >> M >> C;
    vector<int> B(M);
    vector<vector<int>> A(N,vector<int>(M));

    for(int i=0;i<M;i++)
        cin >> B.at(i);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A.at(i).at(j);
        }
    }
    
    int cnt=0;
    int ans;

    for(int i=0;i<N;i++){
        ans = C;
        for(int j=0; j<M; j++){
            ans += A.at(i).at(j) * B.at(j);
        }
        if(ans > 0)
            cnt++;
    }

    cout << cnt << endl;
    return 0;

}