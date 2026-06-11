#include <bits/stdc++.h>
using namespace std;

int vector_max(vector<int> A){//計算量(A.size())
    int max = A.at(0);
    for(int i=0; i<A.size(); i++){
        if (A.at(i) > max){
            max = A.at(i);
        }
    }
    return max;
}

int vector_secondmax(vector<int> A){//second_maxがmaxより真に小さい場合（存在する場合）
    sort(A.begin(), A.end());
    int second_max = A[A.size() - 2];
    return second_max;
}

int main(){
    int n;
    cin >> n;
    vector<int> veven(n/2);
    vector<int> vodd(n/2);
    for(int i=0; i<n/2; i++){
        cin >> vodd[i] >> veven[i];
    }
    vector<int> count_odd(100010, 0);
    vector<int> count_even(100010,0);

    for(int i=0; i<n/2; i++){
        count_odd[vodd[i]-1] ++;
        count_even[veven[i]-1] ++;
    }

    int largeodd = count_odd[0], largeeven = count_even[0], figureodd = 1, figureeven = 1;//largeは多いやつの個数、figureは多いやつの数字
    for(int i=0; i<count_odd.size(); i++){
        if(count_odd[i] > largeodd){
            largeodd = count_odd[i];
            figureodd = i+1;
        }
        if(count_even[i] > largeeven){
            largeeven = count_even[i];
            figureeven = i+1;
        }
    }

    if(figureeven != figureodd){
        cout << n - largeodd - largeeven << endl;
    }

    else{
        int secondodd = vector_secondmax(count_odd), secondeven = vector_secondmax(count_even);

        cout << n -  max(largeeven + secondodd, largeodd + secondeven) << endl;
    }
}