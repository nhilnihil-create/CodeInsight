#include <bits/stdc++.h>
using namespace std;
int time(vector<int> data){
    int time = 0;
    for (int i = 0; i < 5; i++){
        while(!(time % 10 == 0)){
            time ++;
        }
        time += data.at(i);
    }
    return time;
}
int main(){
    vector<int> data(5);
    vector<int> tempdata(5);
    vector<int> timer(120);
    vector<int> next(5);
    for (int i = 0; i < 5; i++){
        cin >> data.at(i);
        tempdata.at(i) = data.at(i);
        next.at(i) = i;
    }
    int i=0;
    do {
        for (int j = 0; j < 5; j++){
            data.at(j) = tempdata.at(next.at(j));
        }
        timer.at(i) = time(data);
        i++;
    } while (next_permutation(next.begin(), next.end()));
    sort(timer.begin(), timer.end());
    cout << timer.at(0) << endl;
}