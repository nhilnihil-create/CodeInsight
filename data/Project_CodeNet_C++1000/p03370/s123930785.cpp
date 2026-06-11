#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll grams;
    int types;
    int lessgrams;
    cin >> types >> grams;
    vector <int> recipe;
    for(int i=0;i<types;i++){
        int number;
        cin >> number;
        recipe.push_back(number);

        grams -= recipe.at(i);
        lessgrams = recipe.at(i);
    }
    for (auto i : recipe){
        if(i<lessgrams)
        lessgrams = i;
    }


    ll result = grams/lessgrams + types;

    cout << result << endl;

}