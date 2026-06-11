#include <bits/stdc++.h>
using namespace std;

const vector<char> AsignVec = {'a', 'b', 'c', 'n'};
const int BigMp = 10000;

int calcMp(vector<int> lenVec, vector<char> bambooAsignVec, vector<int> goalLenVec)
{
    int mp = 0;

    vector<int> finalLenVec(3, 0);

    for (int i = 0; i < lenVec.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (bambooAsignVec.at(i) == AsignVec.at(j))
            {
                if (finalLenVec.at(j) != 0)
                {
                    mp += 10;
                }

                finalLenVec.at(j) += lenVec.at(i);
            }
        }
    }

    bool isZero = false;

    for (int i = 0; i < 3; ++i)
    {
        if (finalLenVec.at(i) == 0)
        {
            isZero = true;
            break;
        }

        mp += abs(finalLenVec.at(i) - goalLenVec.at(i));
    }

    if (isZero)
    {
        return BigMp;
    }
    else
    {
        return mp;
    }
}

int getLeastMp(vector<int> lenVec, vector<char> bambooAsignVec, vector<int> finalLenVec)
{
    if (bambooAsignVec.size() == lenVec.size())
    {
        return calcMp(lenVec, bambooAsignVec, finalLenVec);
    }
    else
    {
        int leastMp = BigMp;

        for (const char &singleNewAsign : AsignVec)
        {
            vector<char> newBambooAsignVec(bambooAsignVec.size());
            copy(bambooAsignVec.begin(), bambooAsignVec.end(), newBambooAsignVec.begin());
            newBambooAsignVec.push_back(singleNewAsign);

            int singleLeastMp = getLeastMp(lenVec, newBambooAsignVec, finalLenVec);

            leastMp = min(leastMp, singleLeastMp);
        }

        return leastMp;
    }
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> lenVec;
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        lenVec.push_back(input);
    }

    int leastMp = getLeastMp(lenVec, {}, {a, b, c});

    cout << leastMp << endl;
}