#include<bits/stdc++.h>

int main(){
    using namespace std;

    const auto& modplus = [](unsigned long i, unsigned long j){return (i + j) % 1000000007;};

    unsigned long N;
    cin >> N;

    vector<unsigned long> dp{1}, prev;

    string S;
    cin >> S;
    for(const auto& c : S){
        unsigned long M{dp.size()};
        dp.swap(prev);
        dp.resize(M + 1);
        fill(begin(dp), end(dp), 0);

        if(c == '<')partial_sum(begin(prev), end(prev), begin(dp) + 1, modplus);
        else partial_sum(rbegin(prev), rend(prev), rbegin(dp) + 1, modplus);
    }

    cout << accumulate(begin(dp), end(dp), 0UL, modplus) << endl;

    return 0;
}