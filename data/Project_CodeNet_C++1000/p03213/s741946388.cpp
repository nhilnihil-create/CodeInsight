#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> isprime(101,true);
    vector<int> primes;
    for (int i=2; i<=100; i++) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j=i+i; j<=100; j+=i) isprime[j] = false;
    }
    vector<int> powers(primes.size(),0);
    for (int i=2; i<=n; i++) {
        int curr = i;
        for (int j=0; j<powers.size(); j++) {
            while (curr%primes[j]==0) {
                curr/=primes[j];
                powers[j]++;
            }
        }
    }
    int result = 0;
    for (auto i : powers) if (i+1>=75) result++;
    /*
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            if ((powers[i]+1>=15 && powers[j]+1>=5) || (powers[i]+1>=5 && powers[j]+1>=15) || (powers[i]+1>=3 && powers[j]+1>=25) || (powers[i]+1>=25 && powers[j]+1>=3)) result++;
        }
    }
    */
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            if (powers[i]+1>=15 && powers[j]+1>=5) result++;
        }
    }
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            if (powers[i]+1>=5 && powers[j]+1>=15) result++;
        }
    }
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            if (powers[i]+1>=3 && powers[j]+1>=25) result++;
        }
    }
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            if (powers[i]+1>=25 && powers[j]+1>=3) result++;
        }
    }
    /*
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            for (int k=j+1; k<powers.size(); k++) {
                if ((powers[i]+1>=3 && powers[j]+1>=5 && powers[k]+1>=5) || (powers[i]+1>=5 && powers[j]+1>=3 && powers[k]+1>=5) || (powers[i]+1>=5 && powers[j]+1>=5 && powers[k]+1>=3)) result++;
            }
        }
    }
    */
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            for (int k=j+1; k<powers.size(); k++) {
                if (powers[i]+1>=3 && powers[j]+1>=5 && powers[k]+1>=5) result++;
            }
        }
    }
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            for (int k=j+1; k<powers.size(); k++) {
                if (powers[i]+1>=5 && powers[j]+1>=3 && powers[k]+1>=5) result++;
            }
        }
    }
    for (int i=0; i<powers.size(); i++) {
        for (int j=i+1; j<powers.size(); j++) {
            for (int k=j+1; k<powers.size(); k++) {
                if (powers[i]+1>=5 && powers[j]+1>=5 && powers[k]+1>=3) result++;
            }
        }
    }
    cout << result;
    return 0;
}