#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    int X;
    cin >>X;
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    sort(vec.begin(),vec.end());
    int count =0;
    for(int i=0;i<N;i++){
        X-=vec.at(i);
        if(X>=0){
            if(i==N-1&&X==0){
                count++ ;
                break;
            }
            else if(i==N-1&&X>0){
                break;
            }
            count ++;
        }
        else{
            break;
        }
    }
    cout << count << endl;
}