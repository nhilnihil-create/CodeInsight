#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class Restaurant {
public:
    Restaurant(int serialNumber, string cityName, int score) : m_serialNumber(serialNumber), m_cityName(cityName), m_score(score) {
    }
    int getSerialNumber() const {
        return m_serialNumber;
    }
    string getCityName() const {
        return m_cityName;
    }
    int getScore() const {
        return m_score;
    }
private:
    const int m_serialNumber;
    const string m_cityName;
    const int m_score;
};
 
bool lexicalOrder(const Restaurant* front, const Restaurant* back);
 
int main() {
    int numOfRestaurant;
    cin >> numOfRestaurant;
    
    vector<Restaurant*> guideBook;
    string cityName;
    int score;
    for (int i = 1; i <= numOfRestaurant; ++i) {
        cin >> cityName >> score;
        guideBook.push_back(new Restaurant(i, cityName, score));
    }
    
    sort(guideBook.begin(), guideBook.end(), lexicalOrder);
    
    for (Restaurant* restaurant : guideBook) {
        cout << restaurant->getSerialNumber() << endl;
    }
 
    for (Restaurant* restaurant : guideBook) {
        delete restaurant;
    }  
    
}
 
bool lexicalOrder(const Restaurant* front, const Restaurant* back) {
    if (front->getCityName() == back->getCityName()) {
        return front->getScore() > back->getScore();
    } else {
        return front->getCityName() < back->getCityName();
    }
}