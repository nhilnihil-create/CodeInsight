#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<string> n_vec;
    map<string,int> n_map;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a ;
        n_vec.push_back(a);
    }

    int M;
    cin >> M;
    vector<string> m_vec;
    map<string,int> m_map;

    for (int i = 0; i < M; i++) {
        string a;
        cin >> a ;
        m_vec.push_back(a);
    }


    //cout << "-1" << endl;

    for (int i = 0; i < n_vec.size(); i++) {

        if (n_map.count(n_vec.at(i)) == 0){
            n_map[n_vec.at(i)] = 1;
        }
        else{
            n_map[n_vec.at(i)] = n_map[n_vec.at(i)] + 1;
        }

    }
    for (int i = 0; i < m_vec.size(); i++) {

        if (m_map.count(m_vec.at(i)) == 0){
            m_map[m_vec.at(i)] = 1;
        }
        else{
            m_map[m_vec.at(i)] = m_map[m_vec.at(i)] + 1;
        }

    }

    //cout << "--------" << endl;

    int max = 0;

    for(auto itr = n_map.begin(); itr != n_map.end(); ++itr)
    {
        //itr.operator->
        string key = itr->first;
        int value = itr->second;

        //cout << key << endl;
        //cout << value << endl;

        int mainasu = m_map[key];

        int keisan = value - mainasu;
        //cout << keisan << endl;

        if (max < keisan){
            max = keisan;
        }


    }

    cout << max << endl;
 
    
}
