#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++){
        cin >> vec.at(i);
    }

    //sort algorith
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N-1; j++){
            if(vec.at(i) > vec.at(j)){
                int A = vec.at(i);
                int B = vec.at(j);
                vec.at(j) = A;
                vec.at(i) = B;
            }
        }
    }

    vector<int> kagami(1);
    for(int i = 0; i < N; i++){
        if(kagami.at(kagami.size()-1) != vec.at(i)){
            kagami.push_back(vec.at(i));
        }
    }
    
    kagami.erase(kagami.begin());
    cout << kagami.size() << endl;
    

}